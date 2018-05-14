/*Beginning of Distance.h*/
/*Header file containing the definition of the Distance
class*/
class Distance
{
		int iFeet;
		float fInches;
	public:
		void setFeet(int); //prototype only
		int getFeet(); //prototype only
		void setInches(float); //prototype only
		float getInches(); //prototype only
		/*function to add the invoking object with another
		object passed as a parameter and return the resultant
		object*/
		Distance add(Distance);
};
Distance& larger(Distance&, Distance&);
/*End of Distance.h*/
