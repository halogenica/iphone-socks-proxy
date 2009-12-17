/*
*/
#import <UIKit/UIKit.h>
enum {
    kSendBufferSize = 32768,
    kReceiveBufferSize = 32768
};


@protocol SocksProxyDelegate <NSObject>
- (void)_updateStatus:(NSString *)statusString;
- (void)_sendreceiveDidStart;
- (void) _sendreceiveDidStopWithStatus:(NSString *)statusString;
@end

@interface SocksProxy : NSObject
{
    NSInputStream *             _receivenetworkStream;
    NSOutputStream *             _sendnetworkStream;
    NSOutputStream *            _fileStream;
    NSInputStream *             _sendfileStream;
    id <SocksProxyDelegate> delegate;
    uint8_t                     _sendbuffer[kSendBufferSize];
    size_t                      _sendbufferOffset;
    size_t                      _sendbufferLimit;
    uint8_t                     _receivebuffer[kReceiveBufferSize];
    size_t                      _receivebufferOffset;
    size_t                      _receivebufferLimit;
	BOOL						_spaceAvailable;
	BOOL						_remotespaceAvailable;
	NSUInteger					_protocolLocation;
}
@property (nonatomic, assign) id <SocksProxyDelegate> delegate;

@property (nonatomic, readonly) BOOL                isSendingReceiving;
- (void)stopSendReceiveWithStatus:(NSString *)statusString;
- (void)startSendReceive:(int)fd;

@end
