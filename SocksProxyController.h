/*
 #  SOCKS - SOCKS Proxy for iPhone
 #  Copyright (C) 2009 Ehud Ben-Reuven
 #  udi@benreuven.com
 #
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
 # as published by the Free Software Foundation version 2.
 #
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
 #
 # You should have received a copy of the GNU General Public License
 # along with this program; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,USA.
 */

#import <UIKit/UIKit.h>
#import "SocksProxy.h"
enum {
	NCONNECTIONS=100
};

@interface SocksProxyController : UIViewController <SocksProxyDelegate, NSNetServiceDelegate>
{
    UILabel *                   _portLabel;
    UILabel *                   _addressLabel;
    UILabel *                   _statusLabel;
	UILabel *					_countOpenLabel;
	UILabel *					_nConnectionsLabel;
    UIActivityIndicatorView *   _activityIndicator;
    UIButton *                  _startOrStopButton;
    
    NSNetService *              _netService;
    CFSocketRef                 _listeningSocket;
	
	NSInteger				_nConnections;
	SocksProxy *			_sendreceiveStream[NCONNECTIONS];
}

@property (nonatomic, retain) IBOutlet UILabel *                   addressLabel;
@property (nonatomic, retain) IBOutlet UILabel *                   portLabel;
@property (nonatomic, retain) IBOutlet UILabel *                   statusLabel;
@property (nonatomic, retain) IBOutlet UILabel *                   countOpenLabel;
@property (nonatomic, retain) IBOutlet UILabel *                   nConnectionsLabel;
@property (nonatomic, retain) IBOutlet UIActivityIndicatorView *   activityIndicator;
@property (nonatomic, retain) IBOutlet UIButton *                  startOrStopButton;

- (IBAction)startOrStopAction:(id)sender;

@end
