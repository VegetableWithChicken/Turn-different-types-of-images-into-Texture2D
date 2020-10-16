
cv::Mat ARSActor::Frames2Mat(const rs2::frame& frame)
{
    /*
	//frame Convet Mat Quick Start;
	int iwidth=frame.as<rs2::video_frame>().get_width();
	int iheight = frame.as<rs2::video_frame>().get_height();
	cv:;Mat Depth_Image=cv::Mat(cv::Size(iwidth, iheight), CV_8UC3, (void*)depth_f.get_data(), cv::Mat::AUTO_STEP);
	//cv::Mat Color_Image = cv::Mat(cv::Size(iwidth, iheight), CV_8UC3, (void*)color_f.get_data(), cv::Mat::AUTO_STEP);
	*/
    auto vf = frame.as<rs2::video_frame>();
	const int w = vf.get_width();
	const int h = vf.get_height();
    if (frame.get_profile().format() == RS2_FORMAT_BGR8)
     {
         return cv::Mat(cv::Size(w, h), CV_8UC3, (void *)frame.get_data(), cv::Mat::AUTO_STEP);
     }

    else if (frame.get_profile().format() == RS2_FORMAT_RGB8)
     {
         auto r = cv::Mat(cv::Size(w, h), CV_8UC3, (void *)frame.get_data(), cv::Mat::AUTO_STEP);
         cv::cvtColor(r, r, CV_RGB2BGR);
         return r;
    }

    else if (frame.get_profile().format() == RS2_FORMAT_Z16)
     {
        return cv::Mat(cv::Size(w, h), CV_16UC1, (void *)frame.get_data(), cv::Mat::AUTO_STEP);
     }

    else if (frame.get_profile().format() == RS2_FORMAT_Y8)
    {
         return cv::Mat(cv::Size(w, h), CV_8UC1, (void *)frame.get_data(), cv::Mat::AUTO_STEP);
    }
	else
	{
	 return cv::Mat(cv::Size(w, h), CV_8UC3, (void *)frame.get_data(), cv::Mat::AUTO_STEP);
	}
}
