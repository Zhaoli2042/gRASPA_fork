#pragma once

#include <cstddef>

inline double DNNHostGuestInteractionEnergy(
    double combined_energy,
    double host_energy,
    double guest_energy)
{
  return combined_energy - host_energy - guest_energy;
}

template <typename Position>
inline size_t CopySelectedDNNAtoms(
    const Position* source,
    Position* destination,
    const bool* selected,
    size_t source_size,
    size_t destination_capacity)
{
  size_t selected_count = 0;
  for(size_t source_index = 0; source_index < source_size; source_index++)
  {
    if(selected[source_index]) selected_count++;
  }

  if(selected_count != destination_capacity) return selected_count;

  size_t destination_index = 0;
  for(size_t source_index = 0; source_index < source_size; source_index++)
  {
    if(!selected[source_index]) continue;
    destination[destination_index++] = source[source_index];
  }
  return selected_count;
}
