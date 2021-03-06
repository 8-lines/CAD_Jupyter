static char help[] ="Tests TS time span \n\n";

#include <petscts.h>

static PetscErrorCode RHSFunction(TS ts,PetscReal t,Vec X,Vec F,void *ctx)
{
  PetscInt          i,n;
  const PetscScalar *xx;
  /* */ PetscScalar *ff;

  PetscFunctionBegin;
  PetscCall(VecGetLocalSize(X,&n));
  PetscCall(VecGetArrayRead(X,&xx));
  PetscCall(VecGetArray(F,&ff));
  if (n >= 1) ff[0] = 1;
  for (i = 1; i < n; i++) ff[i] = (i+1)*(xx[i-1]+PetscPowReal(t,i))/2;
  PetscCall(VecRestoreArrayRead(X,&xx));
  PetscCall(VecRestoreArray(F,&ff));
  PetscFunctionReturn(0);
}

int main(int argc, char *argv[])
{
  TS              ts;
  Vec             X,*Xs;
  PetscInt        i,n,N = 9;
  PetscReal       tspan[3] = {0, 0.5, 1.0};
  const PetscReal *tspan2;

  PetscCall(PetscInitialize(&argc,&argv,NULL,help));
  PetscCall(TSCreate(PETSC_COMM_SELF,&ts));
  PetscCall(TSSetType(ts,TSRK));
  PetscCall(TSSetRHSFunction(ts,NULL,RHSFunction,NULL));
  PetscCall(VecCreateSeq(PETSC_COMM_SELF,N,&X));
  PetscCall(VecZeroEntries(X));
  PetscCall(TSSetTimeSpan(ts,3,tspan));
  PetscCall(TSSetExactFinalTime(ts,TS_EXACTFINALTIME_MATCHSTEP));
  PetscCall(TSSetFromOptions(ts));
  PetscCall(TSSolve(ts,X));
  PetscCall(TSGetTimeSpanSolutions(ts,&n,&Xs));
  PetscCall(TSGetTimeSpan(ts,&n,&tspan2));
  PetscCall(PetscPrintf(PETSC_COMM_WORLD,"Time Span: "));
  for (i=0; i<n; i++) PetscCall(PetscPrintf(PETSC_COMM_WORLD," %g",(double)tspan2[i]));
  PetscCall(PetscPrintf(PETSC_COMM_WORLD,"\n"));
  PetscCall(TSDestroy(&ts));
  PetscCall(VecDestroy(&X));
  PetscCall(PetscFinalize());
  return 0;
}

/*TEST

testset:
  test:
    suffix: 1
    args: -ts_monitor
  test:
    suffix: 2
    args: -ts_monitor -ts_time_span 0,0.3,0.6,1.0
TEST*/
