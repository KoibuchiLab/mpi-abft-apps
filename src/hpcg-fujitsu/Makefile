#===============================================================================
# Copyright 2005-2021 Intel Corporation.
#
# This software and the related documents are Intel copyrighted  materials,  and
# your use of  them is  governed by the  express license  under which  they were
# provided to you (License).  Unless the License provides otherwise, you may not
# use, modify, copy, publish, distribute,  disclose or transmit this software or
# the related documents without Intel's prior written permission.
#
# This software and the related documents  are provided as  is,  with no express
# or implied  warranties,  other  than those  that are  expressly stated  in the
# License.
#===============================================================================

arch = IMPI_IOMP_SKX
setup_file = setup/Make.$(arch)

HPCG_SRC_PATH = /home/proj/atnw/nagasaka/hpcg

include $(setup_file)

HPCG_DEPS = src/CG.o \
	    src/CG_ref.o \
	    src/TestCG.o \
	    src/ComputeResidual.o \
	    src/ExchangeHalo.o \
	    src/GenerateGeometry.o \
	    src/GenerateProblem.o \
	    src/GenerateProblem_ref.o \
	    src/CheckProblem.o \
	    src/MixedBaseCounter.o \
	    src/OptimizeProblem.o \
	    src/ReadHpcgDat.o \
	    src/ReportResults.o \
	    src/OutputFile.o \
	    src/SetupHalo.o \
	    src/SetupHalo_ref.o \
	    src/TestSymmetry.o \
	    src/TestNorms.o \
	    src/WriteProblem.o \
	    src/YAML_Doc.o \
	    src/YAML_Element.o \
	    src/ComputeDotProduct.o \
	    src/ComputeDotProduct_ref.o \
	    src/mytimer.o \
	    src/ComputeOptimalShapeXYZ.o \
	    src/ComputeSPMV.o \
	    src/ComputeSPMV_ref.o \
	    src/ComputeSYMGS.o \
	    src/ComputeSYMGS_ref.o \
	    src/ComputeWAXPBY.o \
	    src/ComputeWAXPBY_ref.o \
	    src/ComputeMG_ref.o \
	    src/ComputeMG.o \
	    src/ComputeProlongation_ref.o \
	    src/ComputeRestriction_ref.o \
	    src/CheckAspectRatio.o \
	    src/GenerateCoarseProblem.o \
	    src/init.o \
	    src/finalize.o

# These header files are included in many source files, so we recompile every file if one or more of these header is modified.
PRIMARY_HEADERS = $(HPCG_SRC_PATH)/src/Geometry.hpp $(HPCG_SRC_PATH)/src/SparseMatrix.hpp $(HPCG_SRC_PATH)/src/Vector.hpp $(HPCG_SRC_PATH)/src/CGData.hpp \
                  $(HPCG_SRC_PATH)/src/MGData.hpp $(HPCG_SRC_PATH)/src/hpcg.hpp
MKL_INCLUDE=$(HPCG_SRC_PATH)/../../include

all: bin/xhpcg$(xhpcg_suff)

bin/xhpcg$(xhpcg_suff): src/main.o $(HPCG_DEPS)
	$(LINKER) $(LINKFLAGS) src/main.o $(HPCG_DEPS) $(HPCG_LIBS) -I$(MKL_INCLUDE) -o bin/xhpcg$(xhpcg_suff)

clean:
	rm -f src/*.o 
#bin/xhpcg$(xhpcg_suff)

.PHONY: all clean

src/main.o: $(HPCG_SRC_PATH)/src/main.cpp $(PRIMARY_HEADERS)
	$(CXX) -c -msse2 -qopenmp -std=c++11 $(HPCG_DEFS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/CG.o: $(HPCG_SRC_PATH)/src/CG.cpp $(HPCG_SRC_PATH)/src/CG.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/CG_ref.o: $(HPCG_SRC_PATH)/src/CG_ref.cpp $(HPCG_SRC_PATH)/src/CG_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/TestCG.o: $(HPCG_SRC_PATH)/src/TestCG.cpp $(HPCG_SRC_PATH)/src/TestCG.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeResidual.o: $(HPCG_SRC_PATH)/src/ComputeResidual.cpp $(HPCG_SRC_PATH)/src/ComputeResidual.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ExchangeHalo.o: $(HPCG_SRC_PATH)/src/ExchangeHalo.cpp $(HPCG_SRC_PATH)/src/ExchangeHalo.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/GenerateGeometry.o: $(HPCG_SRC_PATH)/src/GenerateGeometry.cpp $(HPCG_SRC_PATH)/src/GenerateGeometry.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/GenerateProblem.o: $(HPCG_SRC_PATH)/src/GenerateProblem.cpp $(HPCG_SRC_PATH)/src/GenerateProblem.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/GenerateProblem_ref.o: $(HPCG_SRC_PATH)/src/GenerateProblem_ref.cpp $(HPCG_SRC_PATH)/src/GenerateProblem_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/CheckProblem.o: $(HPCG_SRC_PATH)/src/CheckProblem.cpp $(HPCG_SRC_PATH)/src/CheckProblem.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/MixedBaseCounter.o: $(HPCG_SRC_PATH)/src/MixedBaseCounter.cpp $(HPCG_SRC_PATH)/src/MixedBaseCounter.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/OptimizeProblem.o: $(HPCG_SRC_PATH)/src/OptimizeProblem.cpp $(HPCG_SRC_PATH)/src/OptimizeProblem.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ReadHpcgDat.o: $(HPCG_SRC_PATH)/src/ReadHpcgDat.cpp $(HPCG_SRC_PATH)/src/ReadHpcgDat.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ReportResults.o: $(HPCG_SRC_PATH)/src/ReportResults.cpp $(HPCG_SRC_PATH)/src/ReportResults.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/OutputFile.o: $(HPCG_SRC_PATH)/src/OutputFile.cpp $(HPCG_SRC_PATH)/src/OutputFile.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/SetupHalo.o: $(HPCG_SRC_PATH)/src/SetupHalo.cpp $(HPCG_SRC_PATH)/src/SetupHalo.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/SetupHalo_ref.o: $(HPCG_SRC_PATH)/src/SetupHalo_ref.cpp $(HPCG_SRC_PATH)/src/SetupHalo_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/TestSymmetry.o: $(HPCG_SRC_PATH)/src/TestSymmetry.cpp $(HPCG_SRC_PATH)/src/TestSymmetry.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/TestNorms.o: $(HPCG_SRC_PATH)/src/TestNorms.cpp $(HPCG_SRC_PATH)/src/TestNorms.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/WriteProblem.o: $(HPCG_SRC_PATH)/src/WriteProblem.cpp $(HPCG_SRC_PATH)/src/WriteProblem.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/YAML_Doc.o: $(HPCG_SRC_PATH)/src/YAML_Doc.cpp $(HPCG_SRC_PATH)/src/YAML_Doc.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/YAML_Element.o: $(HPCG_SRC_PATH)/src/YAML_Element.cpp $(HPCG_SRC_PATH)/src/YAML_Element.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeDotProduct.o: $(HPCG_SRC_PATH)/src/ComputeDotProduct.cpp $(HPCG_SRC_PATH)/src/ComputeDotProduct.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeDotProduct_ref.o: $(HPCG_SRC_PATH)/src/ComputeDotProduct_ref.cpp $(HPCG_SRC_PATH)/src/ComputeDotProduct_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/finalize.o: $(HPCG_SRC_PATH)/src/finalize.cpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/init.o: $(HPCG_SRC_PATH)/src/init.cpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/mytimer.o: $(HPCG_SRC_PATH)/src/mytimer.cpp $(HPCG_SRC_PATH)/src/mytimer.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeOptimalShapeXYZ.o: $(HPCG_SRC_PATH)/src/ComputeOptimalShapeXYZ.cpp $(HPCG_SRC_PATH)/src/ComputeOptimalShapeXYZ.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeSPMV.o: $(HPCG_SRC_PATH)/src/ComputeSPMV.cpp $(HPCG_SRC_PATH)/src/ComputeSPMV.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeSPMV_ref.o: $(HPCG_SRC_PATH)/src/ComputeSPMV_ref.cpp $(HPCG_SRC_PATH)/src/ComputeSPMV_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeSYMGS.o: $(HPCG_SRC_PATH)/src/ComputeSYMGS.cpp $(HPCG_SRC_PATH)/src/ComputeSYMGS.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeSYMGS_ref.o: $(HPCG_SRC_PATH)/src/ComputeSYMGS_ref.cpp $(HPCG_SRC_PATH)/src/ComputeSYMGS_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeWAXPBY.o: $(HPCG_SRC_PATH)/src/ComputeWAXPBY.cpp $(HPCG_SRC_PATH)/src/ComputeWAXPBY.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeWAXPBY_ref.o: $(HPCG_SRC_PATH)/src/ComputeWAXPBY_ref.cpp $(HPCG_SRC_PATH)/src/ComputeWAXPBY_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeMG_ref.o: $(HPCG_SRC_PATH)/src/ComputeMG_ref.cpp $(HPCG_SRC_PATH)/src/ComputeMG_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeMG.o: $(HPCG_SRC_PATH)/src/ComputeMG.cpp $(HPCG_SRC_PATH)/src/ComputeMG.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeProlongation_ref.o: $(HPCG_SRC_PATH)/src/ComputeProlongation_ref.cpp $(HPCG_SRC_PATH)/src/ComputeProlongation_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/ComputeRestriction_ref.o: $(HPCG_SRC_PATH)/src/ComputeRestriction_ref.cpp $(HPCG_SRC_PATH)/src/ComputeRestriction_ref.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/GenerateCoarseProblem.o: $(HPCG_SRC_PATH)/src/GenerateCoarseProblem.cpp $(HPCG_SRC_PATH)/src/GenerateCoarseProblem.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

src/CheckAspectRatio.o: $(HPCG_SRC_PATH)/src/CheckAspectRatio.cpp $(HPCG_SRC_PATH)/src/CheckAspectRatio.hpp $(PRIMARY_HEADERS)
	$(CXX) -c $(CXXFLAGS) -I$(HPCG_SRC_PATH)/src -I$(MKL_INCLUDE) $< -o $@

