#include "placavideo.h"
#include <iostream>

//constructori

PlacaVideo::PlacaVideo() : Hardware()
{
    this->memorieVRAM = 0;
    this->areRayTracing = false;
}

PlacaVideo::PlacaVideo(std::string n, std::string p, double pret, int tdp, int vram, bool rayTracing)
    : Hardware(n, p, pret, tdp)
{
    this->memorieVRAM = vram;
    this->areRayTracing = rayTracing;
}

PlacaVideo::~PlacaVideo() {}

//getere

int PlacaVideo::getMemorieVRAM() const
{
    return this->memorieVRAM;
}

bool PlacaVideo::getAreRayTracing() const
{
    return this->areRayTracing;
}

//metode

double PlacaVideo::calculeazaPerformanta() const
{
    // calculam performanta in functie de VRAM si un bonus pentru Ray Tracing
    double scor = (double)this->memorieVRAM * 1.5;
    
    if (this->areRayTracing == true)
    {
        scor += 500.0;
    }
    
    return scor;
}

std::shared_ptr<Hardware> PlacaVideo::clone() const
{
    // facem o copie a placii video curente
    return std::make_shared<PlacaVideo>(*this);
}

//afisare

void PlacaVideo::afisareVirtuala(std::ostream& os) const
{
    os << "\nVRAM:        " << this->memorieVRAM << " GB"
       << "\nRay Tracing: " << (this->areRayTracing ? "DA" : "NU");
}