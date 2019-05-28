/*
 * Revision Control Information
 *
 * $Source: /users/pchong/CVS/sis/sred/chiusura.c,v $
 * $Author: pchong $
 * $Revision: 1.1.1.1 $
 * $Date: 2004/02/07 10:14:11 $
 *
 */
#include "reductio.h"

pset_family
chiusura(genclass,subclass)
int genclass,subclass;

{

   /* Find the chain implied by classj (genclass,subclass) */

  pset_family chain;
  pset implicata, classj;
  int closed,membri;
  int i,j,k;

  chain = sf_new (0, ns);
  implicata = set_new (ns);
  classj = set_new (ns);
  /* compute classj (genclass,subclass) */ 
  set_copy (classj, GETSET(primes, genclass));
  set_remove (classj, subclass);

  /* compute the chain generated by the class (genclass,subclass) */ 

  /* put in front of the chain the generating class */
  /* update the chain */
  sf_addset (chain,classj);

  closed = 0; /* closed is the number of the classes of the chain
                 whose implications have been computed */
  /* while the closed classes are fewer than the generating classes
     linked in the chain */
  while (closed < chain->count)
  {
    closed++; /* closed is the relative address in the chain of the class
                 whose implications are currently computed */

    /* a new class in the chain is closed */
    /* loop on all the inputs */
    for (k=0; k<ni; k++)
    {
      /* find the class implied by the current generating implicant class 
         under the current input */

      /* compute the closure of the class chain[closed-1] */
	  set_clear (implicata, ns);

      for (i=0; i<np; i++) /* loop on the symbolic product terms */
      {
        if (itable[i].ilab-1 == k)
        {
          if (is_in_set (GETSET(chain, itable[i].plab-1), closed-1) &&
               itable[i].nlab != 0)
				set_insert (implicata, itable[i].nlab-1);
        }
      }

      /* if implicata has more  than one state and has not been already
         included in the chain */

	  membri = set_ord (implicata);

      if ( membri >1 && existdf(implicata,chain) != 1)
      {
        /* add the implied class to the chain */

        /* update the chain */
		sf_addset(chain,implicata);
      }
    }

  }

	set_free(implicata);
	set_free(classj);
  return chain;
}
