"""Regression checks for Allegro atomic-energy tensor handling."""

from pathlib import Path


REPO = Path(__file__).resolve().parents[1]
ALLEGRO_HEADER = REPO / 'src_clean' / 'torch_allegro.h'


def test_atomic_energies_are_accumulated_as_float64():
    """Accept float32 or float64 model output without losing precision."""
    source = ALLEGRO_HEADER.read_text()
    tensor_start = source.index(
        'torch::Tensor atomic_energy_tensor ='
    )
    tensor_end = source.index('nstep ++;', tensor_start)
    tensor_block = source[tensor_start:tensor_end]

    assert '.to(torch::kFloat64)' in tensor_block
    assert 'accessor<double, 2>()' in tensor_block
    assert 'double nAtomSum = 0.0;' in tensor_block
    assert 'accessor<float, 2>()' not in tensor_block
