#include "functions.h"
#include <math.h>
#include <string>
#include <sstream>

#define _USE_MATH_DEFINES


double dmsToRadians(int deg, int min, double sec)
{
  return (deg + min / 60.0 + sec / 3600.0) * M_PI * 180.0;
}

double arcsecToRadians(double arcsec)
{
  return arcsec * M_PI * (180.0 * 3600.0);
}

std::ifstream openFile(const std::string &path)
{
  std::ifstream file(path);

  if(!file){
    throw std::runtime_error("Cannot open file: " + path);
  };
  return file;

}

std::vector<Station> readStations(const std::string &path)
{
  auto file = openFile(path);
  std::vector<Station> stations;
  std::string line;
  int lineNumber = 0;

  while (std::getline(file, line)){
    ++lineNumber;
    std::istringstream row(line);
    int id;
    double x, y;
    if (!(row >> id >> x >> y)){
      throw std::runtime_error("Invalid station in " + path + " at line" + std::to_string(lineNumber));
    }
    stations.push_back({id, Eigen::Vector2d(x, y)});
    }
  return stations;
}


