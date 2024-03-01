#include "helperFunction.hpp"
#include "m2.h"
#include "m1.h"
#include "ezgl/application.hpp"
#include "ezgl/graphics.hpp"
#include "cmath"
#include "StreetsDatabaseAPI.h"

double lat_avg;
extern std::vector<Intersection_data> intersections;
int numIntersect = getNumIntersections();

//preload intersection
void load_intersection(){
    lat_avg = 0;
    for(IntersectionIdx i = 0; i < numIntersect; ++i){
        intersections[i].name = getIntersectionName(i);
        intersections[i].position = getIntersectionPosition(i);
        lat_avg += intersections[i].position.latitude();
    }
    lat_avg = lat_avg/numIntersect;
}

//conversion between LatLon and xy coordinate system
double x_from_lon(double longitude){
    return (kEarthRadiusInMeters * longitude * cos(lat_avg) * kDegreeToRadian);
}
double y_from_lat(double latitude){
    return (kEarthRadiusInMeters * latitude kDegreeToRadian);
}
double lon_from_x(double x){
    return (x/(kEarthRadiusInMeters cos(lat_avg) * kDegreeToRadian));
}
double lat_from_y(double y){
    return (y/(kEarthRadiusInMeters * kDegreeToRadian));
}

//visualize all intersections
void drawAllIntersections(ezgl::renderer *g){
    for(size_t i = 0; i < intersections.size(); ++i){
        double x = x_from_lon(intersections[i].position.longitude());
        double y = y_from_lat(intersections[i].position.latitude());

        double width = 100;
        double height = width;
        g->set_color(ezgl::BLACK);
        g->fill_rectangle({x, y}, {x + width, y + height});
    }
}
