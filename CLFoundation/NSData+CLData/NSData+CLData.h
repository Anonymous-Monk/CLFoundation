//
//  NSData+CLData.h
//  CLFoundation
//
//  Created by Mac on 2018/1/23.
//  Copyright © 2018年 Cain. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, CLDataBaseType) {
    
    CLDataBaseType64 = 64,
    CLDataBaseType76 = 76
};

@interface NSData (CLData)

/**
 将指定的图片转成NSData, 可输入指定压缩比例

 @param image UIImage
 @param compressionQuality 压缩比例
 @return NSData
 */
+ (NSData *)cl_compressOriginalImage:(UIImage *)image
                  compressionQuality:(CGFloat)compressionQuality;

/**
 将制定的APNs NSData转成NSString

 @param data NSData
 @return NSString
 */
+ (NSString *)cl_replacingAPNsTokenWithData:(NSData *)data;

#pragma mark - Base 64加密/解密
/**
 将Base 64的字符串转成NSData

 @param string NSString
 @return NSData
 */
+ (NSData *)cl_transformDataWithBase64EncodedString:(NSString *)string;

/**
 将指定的NSData转成64或76的字符串

 @param data NSData
 @param wrapWidth CLDataBaseType
 @return NSString
 */
+ (NSString *)cl_transformBase64EncodedStringWithData:(NSData *)data
                                            wrapWidth:(CLDataBaseType)wrapWidth;

#pragma mark - AES加密/解密
/**
 利用AES加密NSData

 @param key NSString
 @param encryptData NSData
 @return NSData
 */
- (NSData *)cl_encryptedDataWithAESKey:(NSString *)key
                           encryptData:(NSData *)encryptData;

/**
 利用AES解密NSData

 @param key NSString
 @param decryptData NSData
 @return NSData
 */
- (NSData *)cl_decryptedDataWithAESKey:(NSString *)key
                           decryptData:(NSData *)decryptData;

#pragma mark - 3DES加密/解密
/**
 利用3DES加密NSData
 
 @param key NSString
 @param encryptData NSData
 @return NSData
 */
- (NSData *)cl_encryptedDataWith3DESKey:(NSString *)key
                            encryptData:(NSData *)encryptData;

/**
 利用3DES解密NSData
 
 @param key NSString
 @param decryptData NSData
 @return NSData
 */
- (NSData *)cl_decryptedDataWith3DEKey:(NSString *)key
                           decryptData:(NSData *)decryptData;

@end
