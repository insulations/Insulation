#pragma once

#ifdef INS_PLATFORM_WINDOWS
	
#else
	#error Insulation only support windows now!
#endif // INS_PLATFORM_WINDOWS

#define BIT(x) (1<<x)

#define INS_BIND_EVENT_FN(x) std::bind(&x,this,std::placeholders::_1)