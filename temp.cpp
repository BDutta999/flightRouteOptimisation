#include<bits/stdc++.h>

using namespace std;

// Define City structure
struct City {
  string name;
  double latitude;
  double longitude;
};

// Define Flight structure
struct Flight {
  City origin;
  City destination;
  double distance;
  double fuel_consumption;
};

// Function to calculate distance between two cities (Haversine formula)
double calculateDistance(const City& city1, const City& city2) {
  double earthRadius = 6371; // Kilometers

  double lat1Rad = city1.latitude * M_PI / 180;
  double lat2Rad = city2.latitude * M_PI / 180;
  double lon1Rad = city1.longitude * M_PI / 180;
  double lon2Rad = city2.longitude * M_PI / 180;

  double dLat = lat2Rad - lat1Rad;
  double dLon = lon2Rad - lon1Rad;

  double a = sin(dLat / 2) * sin(dLat / 2) +
             cos(lat1Rad) * cos(lat2Rad) * sin(dLon / 2) * sin(dLon / 2);
  double c = 2 * asin(sqrt(a));

  return earthRadius * c;
}

// Function to estimate fuel consumption (more realistic)
double calculateFuelConsumption(const Flight& flight) {
  // Base fuel consumption based on distance
  double base_consumption = flight.distance * 0.005; // Adjust factor based on typical fuel burn per km

  // Add random factor to simulate wind and other variables (0-10% variation)
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> dis(0.9, 1.1);
  double random_factor = dis(gen);

  // Apply adjustments based on aircraft type (example)
  double adjustment = 0;
  if (flight.origin.name == "Los Angeles" && flight.destination.name == "New York") {
    adjustment = 0.05; // Assume larger aircraft for long haul, adjust factor accordingly
  }

  // Calculate final fuel consumption with adjustments
  double final_consumption = base_consumption * random_factor * (1 + adjustment);

  // Provide informative output
  cout << "Estimated fuel consumption for " << flight.origin.name << " to " << flight.destination.name << ":" << endl;
  cout << base_consumption << " liters for base distance" << endl;
  cout << random_factor << " random factor (wind, etc.)" << endl;
  cout << adjustment << " adjustment for aircraft type (example)" << endl;
  cout << final_consumption << " liters total estimated consumption" << endl;

  return final_consumption;

}
Flight createFlight(const City& origin, const City& destination) {
  Flight flight;
  flight.origin = origin;
  flight.destination = destination;
  flight.distance = calculateDistance(origin, destination);
  // Pass the Flight object instead of just distance to calculate fuel consumption
  flight.fuel_consumption = calculateFuelConsumption(flight);
  return flight;
}

int main() {
  // Define some cities (replace with actual data)
  // City city1{"New York", 40.7128, -74.0059};
  // City city2{"Los Angeles", 34.0522, -118.2437};
  // City city3{"Chicago", 41.8819, -87.6231};

  // Create some flights
  // Flight flight1 = createFlight(city1, city2);
  // Flight flight2 = createFlight(city1, city3);
  // Flight flight3 = createFlight(city2, city3);

  City city4{"Kolkata",22.54111111,88.33777778};
  //City city5{"Durgapur",23.55000000,87.32000000};
  City city6 {"Bombay", 19.0901765, 72.868739};
  //19.0901765, 72.868739
//   Flight flight4 = createFlight(city4, city5);
     Flight flight5 = createFlight(city4, city6);
  // Simple route (replace with optimization algorithm)
  cout << "Simple Route: " << city4.name << " -> " << city6.name << " -> " << city4.name << std::endl;

  // Add functionalities like user input, storing flights, and implementing optimization algorithms.

  return 0;
}