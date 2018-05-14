/*Beginning of Distance.h*/
/*Header file containing the definition of the Distance
class*/
class Distance
{
		int iFeet;
		float fInches;
	public:
		void setFeet(int);
		int getFeet() const; //constant function
		void setInches(float);
		float getInches() const; //constant function
		Distance add(Distance) const; //constant function
};
/*End of Distance.h*/
