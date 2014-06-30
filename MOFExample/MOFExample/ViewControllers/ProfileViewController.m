//
//  ProfileViewController.m
//  MOFExample
//
//  Created by Angel Garcia on 27/06/14.
//  Copyright (c) 2014 MyOrder. All rights reserved.
//

#import "ProfileViewController.h"
#import <MyOrder/MyOrder.h>
#import <MyOrder/UI/ViewControllers/MOLoginViewController.h>
#import <MOFramework/MOFramework.h>
#import <MOFramework/Modules/Auth/MOFAuth.h>

@interface ProfileViewController () <UITextFieldDelegate>
@property (strong, nonatomic) IBOutlet UIView *loginView;
@property (strong, nonatomic) IBOutlet UIScrollView *profileView;
@property (strong, nonatomic) IBOutlet UITextField *firstNameField;
@property (strong, nonatomic) IBOutlet UITextField *lastNameField;
@property (strong, nonatomic) IBOutlet UITextField *emailField;

@end

@implementation ProfileViewController


- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self configureLoginStatus];
}

//This method is not used because we use the standard login controller from SDK, but it could be used if custom login view wanted
- (IBAction)login:(id)sender {
    [[MyOrder shared] setPhoneNumber:@"0600000000"];
    [[MyOrder shared] loginWithPassword:@"pass" saveCredentials:NO onSuccess:^{
        //Login performed!
    } error:^(NSError *error) {
    }];
}

- (IBAction)logout:(id)sender {
    [[MyOrder shared] logoutOnSuccess:^{
        [self configureLoginStatus];
    } error:^(NSError *error) {
        [self configureLoginStatus];
    }];
}

- (IBAction)saveChanges:(id)sender {
    [self.view endEditing:YES];
    [self saveUserProfile];
}

- (void)loadUserProfile {
    [[MOFAuthDAO sharedInstance] loadUserWithAnimation:MOFNetworkAnimationHUD
                                              onResult:^(MOFUser *user) {
                                                  [self configureWithUser:user];
                                              } onError:^(NSError *error) {
                                                  NSLog(@"An error happened fetching user profile: %@", [error localizedDescription]);
                                              }];
}

- (void)saveUserProfile {
    [[MOFAuthDAO sharedInstance] updateUserWithEmail:self.emailField.text
                                         mobilePhone:nil
                                           firstName:self.firstNameField.text
                                            lastName:self.lastNameField.text
                                           birthDate:nil
                                           animation:MOFNetworkAnimationHUD
                                            onResult:^(MOFUser *user) {
                                                [self configureWithUser:user];
                                            } onError:^(NSError *error) {
                                                NSLog(@"An error happened saving user profile: %@", [error localizedDescription]);
                                            }];
}

- (void)configureWithUser:(MOFUser *)user {
    self.firstNameField.text = user.firstName;
    self.lastNameField.text = user.lastName;
    self.emailField.text = user.email;
}

- (void)configureLoginStatus {
    if ([MyOrder shared].isLoggedIn) {
        self.loginView.hidden = YES;
        self.profileView.hidden = NO;
        [self loadUserProfile];
    }
    else {
        self.loginView.hidden = NO;
        self.profileView.hidden = YES;
    }
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return NO;
}

@end
