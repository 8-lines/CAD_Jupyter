# --------------------------------------------------------------------

cdef extern from * nogil:
  
    ctypedef const char* PetscFEType
    PetscFEType PETSCFEBASIC
    PetscFEType PETSCFEOPENCL
    PetscFEType PETSCFECOMPOSITE

    int PetscFECreate(MPI_Comm, PetscFE*)
    int PetscFECreateDefault(MPI_Comm, PetscInt, PetscInt, PetscBool, const char [], PetscInt, PetscFE*)
    int PetscFECreateLagrange(MPI_Comm, PetscInt, PetscInt, PetscBool, PetscInt, PetscInt, PetscFE*)
    int PetscFESetType(PetscFE, PetscFEType)
    int PetscFEGetQuadrature(PetscFE, PetscQuadrature*)
    int PetscFEGetFaceQuadrature(PetscFE, PetscQuadrature*)
    int PetscFESetQuadrature(PetscFE, PetscQuadrature)
    int PetscFESetFaceQuadrature(PetscFE, PetscQuadrature)
    int PetscFEDestroy(PetscFE*)
    int PetscFEGetBasisSpace(PetscFE, PetscSpace*)
    int PetscFESetBasisSpace(PetscFE, PetscSpace)
    int PetscFEGetDimension(PetscFE, PetscInt*)
    int PetscFEGetNumComponents(PetscFE, PetscInt*)
    int PetscFESetNumComponents(PetscFE, PetscInt)
    int PetscFEGetNumDof(PetscFE, const PetscInt**)
    int PetscFEGetSpatialDimension(PetscFE, PetscInt*)
    int PetscFEGetTileSizes(PetscFE, PetscInt*, PetscInt*, PetscInt*, PetscInt*)
    int PetscFESetTileSizes(PetscFE, PetscInt, PetscInt, PetscInt, PetscInt)
    int PetscFEGetDualSpace(PetscFE, PetscDualSpace*)
    int PetscFESetDualSpace(PetscFE, PetscDualSpace)
    int PetscFESetFromOptions(PetscFE)
    int PetscFESetUp(PetscFE)

    int PetscFEView(PetscFE, PetscViewer)
    int PetscFEViewFromOptions(PetscFE, PetscObject, char[])
    
