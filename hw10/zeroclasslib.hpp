
#include <vector>

class polynomial {
private:
  std::vector<double> coefficients;
public:
  polynomial( std::vector<double> c );
  bool is_odd() const;
  double evaluate_at(double x) const;
  double operator()(double x) const { return evaluate_at(x); };
};

void find_initial_bounds
( const polynomial &poly,double &left,double &right);

void move_bounds_closer
( const polynomial &poly,double& left,double& right );

double find_zero( const polynomial &poly,double );
