// Generated by dia2code
#ifndef AI__PATHMAP__H
#define AI__PATHMAP__H

#include <vector>
#include <queue>

namespace state {
  class ElementTab;
};
namespace ai {
  class Point;
  class PointCompareWeight;
}

#include "Direction.h"
#include "Point.h"
#include "state/ElementTab.h"
#include "PointCompareWeight.h"

namespace ai {

  /// class Pathmap - 
  class Pathmap {
    // Attributes
  public:
    std::vector<int> weights;
    std::priority_queue<Point, std::vector<Point>,PointCompareWeight> queue;
    std::vector<Direction>  directions;
  private:
    int width     = 0;
    int height     = 0;
    // Operations
  public:
    void init (const state::ElementTab& grid);
    void addSink (Point p);
    void update (const state::ElementTab& grid);
    bool isWall (Point p);
    void chgWeights (Point p);
    int getWeights (Point p);
    // Setters and Getters
  };

};

#endif