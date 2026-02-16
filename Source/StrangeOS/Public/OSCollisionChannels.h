// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

struct EOSCollisionChannel
{
	constexpr static ECollisionChannel ECC_Enemy = ECollisionChannel::ECC_GameTraceChannel1;
	constexpr static ECollisionChannel ECC_Player = ECollisionChannel::ECC_GameTraceChannel1;

};