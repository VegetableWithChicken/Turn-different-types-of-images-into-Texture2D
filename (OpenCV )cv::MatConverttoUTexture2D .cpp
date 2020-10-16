void AzureKinectDevice::Mat2Texture(cv::Mat Src)
{
	if (!Src.empty())
	{
		/*
        //RealSense D435,435i,T and so on ; cv::Mat (CV_8UC3 to use this)
		UTexture2D* Texture = UTexture2D::CreateTransient(Src.cols, Src.rows);
		Texture->SRGB = 0;
		DataSize = frame.cols * frame.rows * ch;
		const uint8 ch = 4;
		uint8* ColorData = new uint8[Datasize];
		for (int y = 0, i = 0; y < Src.rows; ++y)
		{
			for (int x = 0; x < Src.cols; ++x, ++i)
			{
				ColorData[i * ch + 0] = Src.data[i * 3 + 2];
				ColorData[i * ch + 1] = Src.data[i * 3 + 1];
				ColorData[i * ch + 2] = Src.data[i * 3 + 0];
			}
		}
		void* Datas = Texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
		FMemory::Memcpy(Datas, ColorData, DataSize);
		Texture->PlatformData->Mips[0].BulkData.Unlock();
		Texture->UpdateResource();
		*/

        ////KinectDK; cv::Mat (CV_8UC4 to use this)
		UTexture2D* NewTexture = UTexture2D::CreateTransient((int32)Src.cols, (int32)Src.rows);
		NewTexture->SRGB = 0;
		int32 DataSize = Src.cols * Src.rows;
		ColorData.Init(FColor(0, 0, 0, 255), DataSize);

		for (int y = 0; y < Src.rows; ++y)  
		{
			for (int x = 0; x < Src.cols; ++x) 
			{
				int i = x + (y *Src.cols);
				ColorData[i] = FColor(Src.data[i * 4 + 2], Src.data[i * 4 + 1], Src.data[i * 4 + 0], 255);
			}
		}
		void* Datas = NewTexture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
		FMemory::Memcpy(Datas, ColorData.GetData(), ColorData.Num() * sizeof(FColor));
		NewTexture->PlatformData->Mips[0].BulkData.Unlock();
		NewTexture->UpdateResource();	
	}
}
