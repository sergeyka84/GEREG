/*
 * GDebug.h
 *
 *  Created on: 12.09.2017
 *      Author: Sergey Ka
 */

#pragma once


/**
 * @~Russian
 * @brief Проверяет наличие статического метода с указанным именем и прототипом в указанном классе.
 *
 * Драйверы для одного типа устройств (например, генератора тактовой частоты) должны реализовывать
 * определённое API. С помощью этого макроса осуществляется контроль наличия и прототипов методов,
 * обязанных присутствовать в драйверах.
 */
#define CHECK_STATIC_METHOD_EXISTS(typeName, methodName, retType, ...)			\
		template<typename, typename>											\
		struct typeName##HasMethod##methodName;									\
		template<typename U, typename Ret, typename... Args>					\
		struct typeName##HasMethod##methodName<U, Ret(Args...)>					\
		{																		\
			typedef char Yes;													\
			typedef short No;													\
			template<typename T, Ret(Args...) = &T::methodName>					\
			static Yes Test(T*);												\
			static No Test(...);												\
			enum { Value = sizeof(Test(static_cast<U*>(0))) == sizeof(char)};	\
		};																		\
		static_assert(typeName##HasMethod##methodName<typeName, retType( __VA_ARGS__ )>::Value, "Method " #typeName "::" #methodName " not found. Check " #typeName " implementation.");


