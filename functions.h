#pragma once
#include <fstream>
#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <array>
#include <string>

struct Station{
  int id;
  Eigen::Vector2d position;
};

// All distObs have 3 rounds
struct distObs{
  int from;
  int to;
  std::array<double, 3> rounds;
  double sigma;
};

struct angleObs{
  int station;
  int backsight;
  int foresight;
  std::array<double, 3> rounds;
  double sigma;
};

double dmsToRadians(int deg, int min, double sec);

double arcsecToRadians(double arcsec);

std::ifstream openFile(const std::string& path);

std::vector<Station> readStations(const std::string& path);