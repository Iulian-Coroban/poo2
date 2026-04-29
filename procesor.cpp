#include "procesor.h"
#include <iostream>

//constructori

Procesor::Procesor() : Hardware()
{
    this->socket = "Necunoscut";
    this->nrNuclee = 0;
    this->frecventaGHz = 0.0;
}

Procesor::Procesor(std::string n, std::string p, double pret, int tdp, std::string s, int nuclee, double frecv)
    : Hardware(n, p, pret, tdp)
{
    this->socket = s;
    this->nrNuclee = nuclee;
    this->frecventaGHz = frecv;
}

Procesor::~Procesor() {}

//getere

std::string Procesor::getSocket() const
{
    return this->socket;
}

int Procesor::getNrNuclee() const
{
    return this->nrNuclee;
}

double Procesor::getFrecventaGHz() const
{
    return this->frecventaGHz;
}

//metode

double Procesor::calculeazaPerformanta() const
{

    return (double)this->nrNuclee * this->frecventaGHz;
}

std::shared_ptr<Hardware> Procesor::clone() const
{
    return std::make_shared<Procesor>(*this);
}

//afisare

void Procesor::afisareVirtuala(std::ostream& os) const
{
    os << "\nSocket:      " << this->socket
       << "\nNr. Nuclee:  " << this->nrNuclee
       << "\nFrecventa:   " << this->frecventaGHz << " GHz";
}