//k4a RGB image
cv::Mat AzureKinectDevice::K4a2Mat(k4a::image rgb)
{
	int hight = k4a_image_get_height_pixels(rgb.handle());
	int width = k4a_image_get_width_pixels(rgb.handle());
	cv::Mat Color_frame = cv::Mat(hight, width, CV_8UC4, k4a_image_get_buffer(rgb.handle()));
	return Color_frame;
}

//k4a depth image
cv::Mat AzureKinectDevice::k4a2Mat_Depth(k4a::image indepth)
{
	int32 hight = indepth.get_width_pixels();
	int32 width = indepth.get_height_pixels();
	cv::Mat Depth_frame = cv::Mat(hight, width, CV_16UC1, reinterpret_cast<uint16_t*>(k4a_image_get_buffer(indepth.handle())));
	Depth_frame.convertTo(Depth_frame, CV_8UC1, 255.0 / 5000, 0.0);
	cv::Mat outDepth;
	cv::cvtColor(Depth_frame, outDepth, CV_GRAY2RGBA);
	return outDepth;
}
