#!/bin/bash

PROG="${GRINS_TEST_DIR}/reacting_low_mach_regression"

INPUT="${GRINS_TEST_INPUT_DIR}/reacting_low_mach_cantera_regression.in ${GRINS_TEST_DATA_DIR}/reacting_low_mach_cantera_regression.xdr"

PETSC_OPTIONS="-pc_factor_levels 4 -sub_pc_factor_levels 4"

${LIBMESH_RUN:-} $PROG $INPUT $PETSC_OPTIONS 