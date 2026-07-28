This folder contains example simulation input files for modeling CO2 adsorption in Mg-MOF-74 using machine learning potential (Allegro model). Details about Allegro model are available in `ML_potential_details` folder.

By default, gRASPA assumes that the model predicts a host--guest interaction
energy. Models trained to predict the total energy of the combined structure
must instead add the following keyword to `simulation.input`:

```
DNNModelEnergyMode total
```

In `total` mode, gRASPA evaluates the rigid empty framework and isolated rigid
adsorbate once during initialization and subtracts those reference energies
from every combined prediction. The default is
`DNNModelEnergyMode interaction`, which preserves the behavior expected by
this CO2 example.
