//
//  IntroViewController.m
//  Zype
//
//  Created by Александр on 11.04.17.
//  Copyright © 2017 Zype. All rights reserved.
//

#import "IntroViewController.h"
#import <RMStore/RMStore.h>
#import <SVProgressHUD/SVProgressHUD.h>
#import "ACPurchaseManager.h"

@interface IntroViewController ()

@property (strong, nonatomic) IBOutlet UIButton *loginButton;

@end

@implementation IntroViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self confugureView];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)confugureView {
    self.loginButton.layer.borderColor = [UIColor whiteColor].CGColor;
    self.loginButton.layer.borderWidth = 0.5f;
    self.loginButton.hidden = ([[ACPurchaseManager sharedInstance] isActiveSubscription]);
}

#pragma mark - Actions

- (IBAction)restorePurchaseTapped:(id)sender {
    [SVProgressHUD show];
    [[RMStore defaultStore] restoreTransactionsOnSuccess:^(NSArray *transactions) {
        [SVProgressHUD dismiss];
    } failure:^(NSError *error) {
        [SVProgressHUD showErrorWithStatus:error.localizedDescription];
    }];
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
