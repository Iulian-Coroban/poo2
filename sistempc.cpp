#include "sistempc.h"
#include "procesor.h" 
#include <iostream>
#include <algorithm>

//constructori

SistemPC::SistemPC()
{
    this->denumireSistem = "Configuratie Noua";
}

SistemPC::SistemPC(std::string nume)
{
    this->denumireSistem = nume;
}


SistemPC::SistemPC(const SistemPC& data)
{
    this->denumireSistem = data.denumireSistem;
    for (const auto& p : data.piese)
    {
        this->piese.push_back(p->clone());
    }
}

SistemPC& SistemPC::operator=(SistemPC data)
{
    swap(*this, data);
    return *this;
}

SistemPC::~SistemPC() 
{
    this->piese.clear();
}

//metode

void swap(SistemPC& first, SistemPC& second) noexcept
{
    using std::swap;
    swap(first.denumireSistem, second.denumireSistem);
    swap(first.piese, second.piese);
}
void SistemPC::adaugaPiesa(const std::shared_ptr<Hardware>& piesaNoua)
{
    this->piese.push_back(piesaNoua->clone());
}

void SistemPC::afisareSistem() const
{
    std::cout << "\n========== RAPORT SISTEM: " << this->denumireSistem << " ==========\n";
    for (const auto& p : this->piese)
    {
        std::cout << *p << "\n";
    }
    std::cout << "====================================================\n";
}

double SistemPC::calculPerformantaMedie() const
{
    if (this->piese.empty()) return 0.0;

    double suma = 0;
    for (const auto& p : this->piese)
    {
        suma += p->calculeazaPerformanta();
    }
    return suma / this->piese.size();
}

int SistemPC::numaraProcesoare() const
{
    int count = 0;
    for (const auto& p : this->piese)
    {
        if (std::dynamic_pointer_cast<Procesor>(p))
        {
            count++;
        }
    }
    return count;
}