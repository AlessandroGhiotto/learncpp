class Base
{
  public:
    int m_public {};

  protected:
    int m_protected {};

  private:
    int m_private {};
};

/// PUBLIC
class Pub : public Base // note: public inheritance
{
    // Public inheritance means:
    // Public inherited members stay public (so m_public is treated as public)
    // Protected inherited members stay protected (so m_protected is treated as protected)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
  public:
    Pub()
    {
        m_public = 1;    // okay: m_public was inherited as public
        m_protected = 2; // okay: m_protected was inherited as protected
        // m_private = 3;   // not okay: m_private is inaccessible from derived class
    }
};

/// PRIVATE
class Pri : private Base // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private (so m_public is treated as private)
    // Protected inherited members become private (so m_protected is treated as private)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
  public:
    Pri()
    {
        m_public = 1;    // okay: m_public is now private in Pri
        m_protected = 2; // okay: m_protected is now private in Pri
        // m_private = 3;   // not okay: derived classes can't access private members in the base class
    }
};

int main()
{
    // Outside access uses the access specifiers of the class being accessed.
    Base base;
    base.m_public = 1; // okay: m_public is public in Base
    // base.m_protected = 2; // not okay: m_protected is protected in Base
    // base.m_private = 3;   // not okay: m_private is private in Base

    /// PUBLIC
    Pub pub;
    pub.m_public = 1; // okay: m_public is public in Pub
    // pub.m_protected = 2; // not okay: m_protected is protected in Pub
    // pub.m_private = 3;   // not okay: m_private is inaccessible in Pub

    /// PRIVATE
    Pri pri;
    // pri.m_public = 1;    // not okay: m_public is now private in Pri
    // pri.m_protected = 2; // not okay: m_protected is now private in Pri
    // pri.m_private = 3;   // not okay: m_private is inaccessible in Pri

    return 0;
}
