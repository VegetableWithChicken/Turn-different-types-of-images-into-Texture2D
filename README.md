# k4a::image to Texture2D
# AzureKinectDK
# RealSense D435 D435i
How to convert k4a::imge(k4a_image_t) to UTexture2D
1,u should Convert k4a::image to  k4a_image_t;
(k4a_image_t=k4a::image.handle());
2, convert k4a_image_t to cv::Mat;
3, cv::Mat to UTexture2D;
cv::Mat(rows, cols, CV_8UC4, (void*)buffer, cv::Mat::AUTO_STEP);
4,Convert Ka4::image to Texture2D
use function k4a2Texture(k4a::image inImg)

