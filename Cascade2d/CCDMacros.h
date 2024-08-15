#pragma once
#include <functional>

#define CCD_CALLBACK_0(method, object)	std::bind(&method, object);	
#define CCD_CALLBACK_1(method, object)	std::bind(&method, object, std::placeholders::_1);	
#define CCD_CALLBACK_2(method, object)	std::bind(&method, object, std::placeholders::_1, std::placeholders::_2);	
#define CCD_CALLBACK_3(method, object)	std::bind(&method, object, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);	
#define CCD_CALLBACK_4(method, object)	std::bind(&method, object, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);	
#define CCD_CALLBACK_5(method, object)	std::bind(&method, object, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);	