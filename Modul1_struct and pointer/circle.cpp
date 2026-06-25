#include "circle.h"
#include <cmath> 
double distance(const Circle * c, const Point * p) {
    double dx = p->x - c->centre.x;
    double dy = p->y - c->centre.y;
    double jarak_ke_pusat = std::sqrt((dx * dx) + (dy * dy));
    return jarak_ke_pusat - c->radius;
}
std::string CheckPointInCircle(double selisih) {
    if (std::abs(selisih) < EPSILON) {
        return "On Circle";
    } 
    else if (selisih < 0) {
        return "Inside";
    } 
    else {
        return "Outside";
    }
}