cv::Mat AzureKinectDevice::K4a2Mat(k4a::image rgb)
{
	int hight = k4a_image_get_height_pixels(rgb.handle());
	int width = k4a_image_get_width_pixels(rgb.handle());
	cv::Mat Color_frame = cv::Mat(hight, width, CV_8UC4, k4a_image_get_buffer(rgb.handle())).clone();
	//if u use depth image , depth_image is just one channel ,and 16bit ;8 bit not to save it  ,and u should :
	//first :cv::Mat Depth_frame = cv::Mat(hight, width, CV_16UC1, reinterpret_cast<uint16_t*>k4a_image_get_buffer(rgb.handle())).clone();
	//second :  Depth_frame.convertTo(Depth_frame, CV_8UC1, 255.0 / 5000, 0.0);
	//third: return Depth_frame;
	
	return Color_frame;
}
