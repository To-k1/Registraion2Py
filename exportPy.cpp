#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>
#include <iostream>
#include "Registrator.h"





BOOST_PYTHON_MODULE(registration_py)
{
	//class of default constructor
	boost::python::class_<Registrator>("Registrator")
		.def(boost::python::init<const Registrator&>())
		.def("isPaused", &Registrator::isPaused)
		.def("worker_pause", &Registrator::worker_pause)
		.def("worker_resume", &Registrator::worker_resume)
		.def("Registrating", &Registrator::Registrating)
		.def("HandleResults", &Registrator::HandleResults)
		.def("HandlePause", &Registrator::HandlePause)
		.def("SendProcess", &Registrator::SendProcess);
	//.def("print", &Message::get); //不可以使用print这种关键字作为导出函数名
}

