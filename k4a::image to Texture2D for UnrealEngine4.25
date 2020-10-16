void AzureKinectDevice::k4a2TextureRGB(k4a::image inImg)
{

	uint8_t* data = inImg.get_buffer();
	int T_Width = inImg.get_width_pixels();
	int T_height = inImg.get_height_pixels();
	UTexture2D* NewTexture = UTexture2D::CreateTransient((int32)T_Width, (int32)T_height);
	//if it's size is stable，shouldn't create Utexture2D in while() loop func or tick 
	void* Datas = NewTexture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(Datas, data, inImg.get_size());
	//call of tick or while(1), FMemory::Memcpy will cause RAM increasing to almost full ,although Temporary object will be released
	//suggest :  FMemory::Memmove(Datas, data, inImg.get_size());
	NewTexture->PlatformData->Mips[0].BulkData.Unlock();
	NewTexture->UpdateResource();
}
