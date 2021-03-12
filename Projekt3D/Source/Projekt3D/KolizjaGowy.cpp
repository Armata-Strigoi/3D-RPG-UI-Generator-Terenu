// Fill out your copyright notice in the Description page of Project Settings.


#include "KolizjaGowy.h"

UKolizjaGowy::UKolizjaGowy()
{
	this->kolizja = false;
	this->OnComponentBeginOverlap.AddDynamic(this, &UKolizjaGowy::OnOverlapBegin);
	this->OnComponentEndOverlap.AddDynamic(this, &UKolizjaGowy::OnOverlapEnd);
}

bool UKolizjaGowy::sprawdz()
{
	return kolizja;
}


void UKolizjaGowy::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	kolizja=true;
}

void UKolizjaGowy::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	kolizja=false;
}

