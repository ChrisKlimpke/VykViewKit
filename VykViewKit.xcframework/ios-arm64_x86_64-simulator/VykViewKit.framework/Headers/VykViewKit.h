//
//  VykViewKit.h
//  VykViewKit
//
//  Created by Chris on 09/04/2021.
//

#import <Foundation/Foundation.h>

#import <SceneKit/SceneKit.h>
#import <Accelerate/Accelerate.h>
#import <Metal/Metal.h>
#import <Metal/MTLTexture.h>

#import "TrackerSDKv2/vkTracker.h"

//! Project version number for VykViewKit.
FOUNDATION_EXPORT double VykViewKitVersionNumber;

//! Project version string for VykViewKit.
FOUNDATION_EXPORT const unsigned char VykViewKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <VykViewKit/PublicHeader.h>

FOUNDATION_EXPORT @interface ImageRenderer : NSObject

- (void )                    setStaticImageMode:(bool )setOrClear lensFactor:(float )lensFactor;

- (_Nonnull id)              initWithSceneView: (nonnull SCNView *) scnView
                                    lensFactor: (float )lensFactor
                                      useARKit: (bool )useArKit;

- (void)                  updateImageUsingTrkr: ( vkTracker * _Nonnull ) trkr
                                    forFrameId: (UInt32) frameId
                          availableObjectCount: (int ) availableObjectsCount
                                      viewPort: (CGSize )viewPort;

- (void )setOrientationAngleRadians ;
- (void )setRotationCamera:(float )newRotationRadians ;
- (void ) updateCameraDisplayMatricies ;
- (void )setReflection:(bool ) reflected ;

- (SCNMatrix4) updateOccluderMaterialUsingTrkr: (vkTracker * _Nonnull) trkr forFrameId: (UInt32) frameId atIndex: (int) objectIndex returningZAxisRotation: (float * _Nonnull) zRotation;

-(void )TriggerBulkRecord:(UIViewController *_Nonnull)parent button:(UIButton *_Nonnull)sigButton frames:(int )frames;

-(void )setDebugView:(UIView *_Nonnull)view ;

- (UIImage *)convertTexturetoUIImage:(id<MTLTexture> ) texture
                            jpegData:(NSData **)jpegData
                    imageOrientation:(UIImageOrientation )imageOrientation;

- (bool )createSharedCVPxBfrToMTLTexture:(CGSize         )size
                           cvPixelFormat:(OSType         )cvPixelFormat
                          mtlPixelFormat:(MTLPixelFormat )mtlPixelFormat;
-(id<MTLTexture> _Nullable )getSharedCVMTLtexture ;
-(MTLRenderPassDescriptor * _Nullable)getShardedRenderPassDescriptor ;
-(void )DebugDisplayMTLTexture:(id<MTLTexture>  _Nonnull)texture ;
-(CVPixelBufferRef  _Nonnull)getShardedCVPixelBuffer;

@property(nonatomic, readonly) SCNMaterial * _Nonnull legAndTrousersOccluderMaterial;
@property(nonatomic, readonly) SCNMaterial * _Nonnull footLegAndTrousersOccluderMaterial;
@property(nonatomic, readonly) SCNMaterial * _Nonnull trousersOccluderMaterial;

@end

