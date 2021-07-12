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


//if 16 bit depth image,you should change the UTexture2D format like this  
UTexture2D* AzureKinectDevice::CreateNewTexture(int w, int h, EPixelFormat InFormat)
{
	UTexture2D* tex = UTexture2D::CreateTransient(w, h, InFormat);
	tex->AddressX = TextureAddress::TA_Mirror;
	tex->AddressY = TextureAddress::TA_Mirror;
	tex->Filter = TextureFilter::TF_Bilinear;
	tex->RefreshSamplerStates();
	tex->UpdateResource();
	return tex;
}

void AzureKinectDevice::MakeTexture(const k4a::image& inImg)
{
	//if runtime update Utexture2D* ,you should create inMem as global var;
	Utexture2D* inMem = CreateNewTexture((int32)1920, (int32)1080, EPixelFormat::PF_G16);//传输16bit的深度图
	void* Datas = inMem->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memmove(Datas, inImg.get_buffer(), inImg.get_size());
	inMem->PlatformData->Mips[0].BulkData.Unlock();
	inMem->UpdateResource();
	
}



