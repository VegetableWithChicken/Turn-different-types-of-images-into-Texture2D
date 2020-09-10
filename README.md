# k4a_image_t-to-UTexture2D

How to convert k4a::imge(k4a_image_t) to UTexture2D
1,u should Convert k4a::image to k4a_image_t;
(k4a_image_t=k4a::image.handle());
2, convert k4a_image_t to cv::Mat;
3, cv::Mat to UTexture2D;
cv::Mat(rows, cols, CV_8UC4, (void*)buffer, cv::Mat::AUTO_STEP);
