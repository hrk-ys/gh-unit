//
//  GHMockNSURLConnection.h
//  GHUnit
//
//  Created by Gabriel Handford on 4/9/09.
//  Copyright 2009. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//

#import <Foundation/Foundation.h>

extern NSString *const GHMockNSURLConnectionException;

@interface GHMockNSURLConnection : NSObject {
	NSURLRequest *request_;
	id delegate_; // weak
	
	BOOL cancelled_;
}

@property (readonly, nonatomic, getter=isCancelled) BOOL cancelled;

/*!
 Send generic response to delegate after delay.
 @param delay Delay in seconds (if < 0, there is no delay)
 */
- (void)receiveResponse:(NSURLResponse *)response afterDelay:(NSTimeInterval)delay;

/*!
 Send HTTP response to delegate with status code, headers, after delay.
 This is only the HTTP response (and not data or finished).
 @param statusCode HTTP status code
 @param headers Headers
 @param delay Delay in seconds (if < 0, there is no delay)
 */
- (void)receiveHTTPResponseWithStatusCode:(int)statusCode headers:(NSDictionary *)headers afterDelay:(NSTimeInterval)delay;

/*!
 Send data to connection delegate after delay.
 @param data Data to send
 @param delay Delay in seconds
 */
- (void)receiveData:(NSData *)data afterDelay:(NSTimeInterval)delay;

/*!
 Calls connectionDidFinish: delegate after delay.
 @param delay Delay in seconds (if < 0, there is no delay)
 */
- (void)finishAfterDelay:(NSTimeInterval)delay;

/*!
 Sends mock response, sends data, and then calls finish.
 @param path Data to load path from. File should be available in Test target (bundle)
 @param statusCode Status code for response
 @param MIMEType Content type for response header
 @param afterDelay Delay before responding (if < 0, there is no delay)
 */
- (void)receiveFromPath:(NSString *)path statusCode:(NSInteger)statusCode MIMEType:(NSString *)MIMEType afterDelay:(NSTimeInterval)delay;

@end
