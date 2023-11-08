// Rental.hh
#ifndef RENTAL_HH
#define RENTAL_HH
#include "Movie.hh"

class Rental {
public:
  Rental( const Movie& movie, int daysRented );

  int getDaysRented() const;
  const Movie& getMovie() const;
  double amountFor();

private:
  Movie _movie;
  int _daysRented;
};

inline Rental::Rental( const Movie& movie, int daysRented ):
  _movie( movie ),
  _daysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return _daysRented; }

inline const Movie& Rental::getMovie() const { return _movie; }

double Rental::amountFor()
{
  double thisAmount = 0;
  Rental &each = *this;

  // determine amounts for each line
  switch (each.getMovie().getPriceCode())
  {
  case Movie::REGULAR:
    thisAmount += 2;
    if (each.getDaysRented() > 2)
      thisAmount += (each.getDaysRented() - 2) * 1.5;
    break;
  case Movie::NEW_RELEASE:
    thisAmount += each.getDaysRented() * 3;
    break;
  case Movie::CHILDRENS:
    thisAmount += 1.5;
    if (each.getDaysRented() > 3)
      thisAmount += (each.getDaysRented() - 3) * 1.5;
    break;
  }

  return thisAmount;
}

#endif // RENTAL_HH
