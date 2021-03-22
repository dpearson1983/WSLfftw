#include <iostream>
#include <random>
#include <fftw3.h>

int main() {
    int N = 64;
    std::random_device seeder;
    std::mt19937_64 gen(seeder());
    std::uniform_real_distribution<double> dist(0.0,1.0);

    std::vector<double> dr(N*N*2*(N/2 + 1));
    fftw_plan dr2dk = fftw_plan_dft_r2c_3d(N, N, N, dr.data(), (fftw_complex *)dr.data(), FFTW_ESTIMATE);

    for (int i = 0; i < dr.size(); ++i)
        dr[i] = dist(gen);
    
    fftw_execute(dr2dk);

    return 0;
}