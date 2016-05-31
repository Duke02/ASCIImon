#ifndef VECTOR2_H_INCLUDED
#define VECTOR2_H_INCLUDED

template < typename T >
struct Vector2
{
    int x = 0;
    int y = 0;

    Vector2 () = default;

    Vector2 ( const int x, const int y)
    :   x ( x )
    ,   y ( y )
    { }

    const Vector2<T>
    operator +( const Vector2<T>& other ) const
    {
        return Vector2( x + other.x, y + other.y );
    }

    const Vector2<T>
    operator +=( const Vector2<T>& other ) const
    {
        return Vector2( x + other.x, y + other.y );
    }

    void
    reset ()
    {
        x = 0;
        y = 0;
    }

    explicit operator bool() const
    {
        bool b = false;
        if ( x ) b = true;
        if ( y ) b = true;

        return b;
    }
};

typedef Vector2<int> Vector2i;

#endif // VECTOR2_H_INCLUDED
