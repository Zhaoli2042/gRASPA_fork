#include "dnn_energy_reference.h"

#include <cassert>
#include <cmath>

int main()
{
  const double combined = -1007.25;
  const double host = -1000.0;
  const double guest = -5.0;

  const double interaction =
      DNNHostGuestInteractionEnergy(combined, host, guest);

  assert(std::abs(interaction - (-2.25)) < 1.0e-12);
  assert(DNNHostGuestInteractionEnergy(3.0, 1.0, 2.0) == 0.0);

  const int source[] = {10, 20, 30, 40};
  const bool selected[] = {true, false, true, true};
  int destination[] = {0, 0, 0};
  const size_t copied =
      CopySelectedDNNAtoms(source, destination, selected, 4, 3);
  assert(copied == 3);
  assert(destination[0] == 10);
  assert(destination[1] == 30);
  assert(destination[2] == 40);

  int guarded_destination[] = {-1, -1, 99};
  const size_t overflow_count =
      CopySelectedDNNAtoms(source, guarded_destination, selected, 4, 2);
  assert(overflow_count == 3);
  assert(guarded_destination[0] == -1);
  assert(guarded_destination[1] == -1);
  assert(guarded_destination[2] == 99);
  return 0;
}
