//
//  SocksProxyController_TableView.m
//  SOCKS
//
//  Created by C. Bess on 9/5/10.
//  Copyright 2010 Christopher Bess. All rights reserved.
//

#import "SocksProxyController_TableView.h"

/*!
 * Specifies the sections of the table
 */
typedef enum {
	SocksProxyTableSectionGeneral,
	SocksProxyTableSectionConnections,
	SocksProxyTableSectionCount
} SocksProxyTableSection;

/*!
 * Specifies the rows of the table sections
 */
typedef enum {
	SocksProxyTableRowAddress,
	SocksProxyTableRowPort,
	// connections section
	SocksProxyTableRowConnectionsOpen = 0,
	SocksProxyTableRowConnections
} SocksProxyTableRow;

@implementation SocksProxyController (TableView)

#pragma mark Table View Data Source Methods

- (NSString *)tableView:(UITableView *)table titleForHeaderInSection:(NSInteger)section
{	
	#pragma unused(table)
	
	if (section == SocksProxyTableSectionConnections)
		return @"Connections";
	
    return nil;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)table
{
	#pragma unused(table)
	
    return SocksProxyTableSectionCount;
}

- (NSInteger)tableView:(UITableView *)table numberOfRowsInSection:(NSInteger)section 
{	
	#pragma unused(table)
	
	switch (section)
	{
		case SocksProxyTableSectionGeneral:
			return 2;
			
		case SocksProxyTableSectionConnections:
			return 2;
	}
	
	return 0;
}

- (UITableViewCell *)tableView:(UITableView *)table cellForRowAtIndexPath:(NSIndexPath *)indexPath 
{
	#pragma unused(table)
	static NSString * cellId = @"cellid";
	
	UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue2
												   reuseIdentifier:cellId];
	cell.accessoryType = UITableViewCellAccessoryNone;
	cell.accessoryView = nil;
    
	NSString *text = nil; // the caption
	NSString *detailText = nil;
	
	switch (indexPath.section)
	{
		case SocksProxyTableSectionGeneral:
			switch (indexPath.row)
			{
				case SocksProxyTableRowAddress:
					text = @"address";
					detailText = self.currentAddress;
					if (self.currentAddress.length == 0)
						detailText = @"n/a";
					break;
					
				case SocksProxyTableRowPort:
					text = @"port";
					if (self.currentPort)
						detailText = [[NSNumber numberWithInt:self.currentPort] stringValue];
					else
						detailText = @"n/a";
					break;
			}
			break;
			
		case SocksProxyTableSectionConnections:
			switch (indexPath.row)
			{
				case SocksProxyTableRowConnections:
					text = @"count";
					detailText = [[NSNumber numberWithInt:self.currentConnectionCount] stringValue];
					break;
					
				case SocksProxyTableRowConnectionsOpen:
					text = @"open";
					detailText = [[NSNumber numberWithInt:self.currentOpenConnections] stringValue];
					break;
			}
			break;
	}
	
	// set the field label title
    cell.textLabel.text = text;
	
	// set the cell text
    cell.detailTextLabel.text = detailText;
	
	return [cell autorelease];
}

@end
