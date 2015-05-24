/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PPB_ann.c
 *
 * Code generation for function 'PPB_ann'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "PPB_ann.h"

/* Function Definitions */
double PPB_ann(const double x1[16])
{
  double xp1[16];
  int k;
  static const double settings_gain[16] = { 0.00373775883979966,
    0.111111111111111, 0.0926822712717398, 0.00151381078706761, 2.0,
    0.333333333333333, 0.0188679245283019, 0.0208333333333333,
    0.0588235294117647, 0.0645161290322581, 0.027027027027027, 0.2,
    0.00586066846784544, 0.0555555555555556, 0.4, 0.666666666666667 };

  static const double settings_xoffset[16] = { 4.44, 0.0, -10.2249, 129.0924632,
    0.0, 0.0, 9.0, 10.0, 1.0, 0.0, 3.0, 0.0, 27.6414, 0.0, 0.0, 0.0 };

  double b[15];
  static const double a[15] = { -1.0949, 0.1578, -1.0076, -0.072769, 0.21478,
    -0.63659, 0.081539, 0.92528, 0.49196, -0.044517, -0.23289, -1.1156, 0.10515,
    -0.042605, 0.21595 };

  double b_b[15];
  double d0;
  int i0;
  static const double b_a[240] = { 0.85229, -1.3422, -2.0811, -2.3083, 0.51964,
    -2.298, 1.0244, 0.17627, -0.62374, 0.017481, 0.65004, -0.9124, -1.3574,
    -0.074445, 0.17087, -0.82042, -0.60769, -0.33725, -0.065702, 0.33948, 1.3837,
    0.060331, 0.28518, 0.25615, 0.056457, 2.2897, -2.9448, 0.34568, -0.16574,
    -1.7264, 0.13568, 1.2143, -3.1289, -1.3536, 0.046597, -2.7262, 0.39486,
    -1.8086, 1.0287, 0.051616, -1.4972, -1.6022, 1.3561, -0.20405, 0.89463,
    0.48278, -0.19361, -0.22499, -0.81951, 0.079472, -0.99428, -0.52439,
    -0.0066224, -0.75794, 0.028614, -1.1772, -0.5226, -0.47005, -0.22, 0.029911,
    0.60861, -0.51786, 0.45401, -0.025592, -0.22352, -0.34975, 0.23135, -0.53737,
    -0.093051, 0.023595, 0.20699, 1.1927, -0.11272, -0.074485, -0.21467, 1.365,
    0.13254, 0.053542, 1.2083, -0.081078, -0.030797, 0.57108, -1.0222, 0.56798,
    0.016337, 0.16316, 1.1546, -0.075744, 0.069251, -0.26756, -0.60126, 0.39247,
    -0.24868, 0.61703, 0.19727, 0.31865, -0.34352, -0.039972, 0.58391, 0.063881,
    -0.3565, -0.020981, 0.0059788, -0.40401, 0.43119, -0.6085, 1.0761, 0.74614,
    0.51101, 0.23611, 0.25126, -0.12036, -0.49089, 0.43766, 0.039647, -0.19833,
    -0.56652, 0.032331, -0.40712, 0.79688, -0.058832, 0.3462, 0.85515, -0.30589,
    0.61368, -0.81463, 0.79596, 0.15221, -0.45236, 0.035042, -1.3678, -0.72471,
    -0.29118, -0.21554, -0.71783, -1.5484, -0.10528, 1.2216, -1.6963, 0.68043,
    0.5221, 1.1685, 1.7573, 0.62115, 0.072624, -0.32423, -0.45894, -0.8775,
    0.024278, 0.063914, -0.69585, -0.89216, 0.71858, 0.81313, 0.33999, -0.14821,
    -0.9387, -0.038095, 1.4806, 0.073145, -0.14404, -0.11403, 0.071247, -0.2913,
    0.20354, -1.6633, 0.71263, 1.2136, -2.0941, 0.57303, -0.42525, -0.099282,
    -1.9712, -1.1779, -0.069745, -1.1304, 2.9748, -0.38822, 0.44438, -1.0327,
    -0.65062, 0.12091, -0.78543, 0.023012, 0.0045196, 0.18641, -0.61698,
    0.076876, 0.13558, 0.042685, -0.58085, 0.64052, -0.30638, -0.37016, 1.0909,
    0.19634, 2.7928, -2.4751, 0.73384, -0.28887, 1.4238, 0.93245, 0.44598,
    -1.0354, 0.060168, -0.42596, -0.5939, -0.026639, -0.70861, 1.126, 1.42,
    0.53701, -1.2201, 1.7283, 0.1957, -1.6585, 0.29982, 1.6284, 0.7994, 0.1044,
    0.86893, -0.14001, 0.50105, -0.62963, -0.76243, -1.1723, -0.44808, -1.1112,
    0.921, 0.023675, 0.96547, -0.89432, 0.54811, 0.41432, 0.02285, -0.2005,
    -1.0607, -0.91218, 0.17561, 1.8945 };

  double x[15];
  static const double c_a[16] = { -0.14073, -0.36845, -0.26943, -0.17101,
    -0.15097, -0.086474, -0.29444, -0.14252, -0.16484, -0.44713, -0.32461,
    0.29126, -0.20499, -0.30132, -0.49568, -0.012194 };

  double d1;
  static const double d_a[15] = { -3.3923, 3.3525, 3.9739, 2.9552, -1.2428,
    -3.4997, 2.0944, -3.2363, -2.5642, -0.23309, 2.8181, -3.1271, -1.6086,
    1.3437, 2.7309 };

  /* MYNEURALNETWORKFUNCTION neural network simulation function. */
  /*  */
  /*  Generated by Neural Network Toolbox function genFunction, 23-Apr-2015 14:24:16. */
  /*   */
  /*  [y1] = myNeuralNetworkFunction(x1) takes these arguments: */
  /*    x = 16xQ matrix, input #1 */
  /*  and returns: */
  /*    y = 1xQ matrix, output #1 */
  /*  where Q is the number of samples. */
  /*  ===== NEURAL NETWORK CONSTANTS ===== */
  /*  Input 1 */
  /*  Layer 1 */
  /*  Layer 2 */
  /*  Output 1 */
  /*  ===== SIMULATION ======== */
  /*  Dimensions */
  /*  samples */
  /*  Input 1 */
  /*  ===== MODULE FUNCTIONS ======== */
  /*  Map Minimum and Maximum Input Processing Function */
  for (k = 0; k < 16; k++) {
    xp1[k] = (x1[k] - settings_xoffset[k]) * settings_gain[k] + -1.0;
  }

  /*  Layer 1 */
  memcpy(&b[0], &a[0], 15U * sizeof(double));

  /*  Sigmoid Symmetric Transfer Function */
  for (k = 0; k < 15; k++) {
    d0 = 0.0;
    for (i0 = 0; i0 < 16; i0++) {
      d0 += b_a[k + 15 * i0] * xp1[i0];
    }

    b_b[k] = b[k] + d0;
  }

  for (k = 0; k < 15; k++) {
    x[k] = exp(-2.0 * b_b[k]);
  }

  /*  Layer 2 */
  /*  Output 1 */
  /*  Map Minimum and Maximum Output Reverse-Processing Function */
  d0 = 0.0;
  for (k = 0; k < 16; k++) {
    d0 += c_a[k] * xp1[k];
  }

  d1 = 0.0;
  for (k = 0; k < 15; k++) {
    d1 += d_a[k] * (2.0 / (1.0 + x[k]) - 1.0);
  }

  return (((0.29888 + d0) + d1) - -1.0) / 0.02000400080016;
}

/* End of code generation (PPB_ann.c) */