/**
 *  NativeFunction.h
 *
 *  The NativeFunction class is an extension of the Function class that
 *  forwards the function call directly to a native function in C/C++
 *
 *  @author Emiel Bruijntjes <emiel.bruijntjes@copernica.com>
 *  @copyright 2013 Copernica BV
 */

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Class definition
 */
class NativeFunction : public Function
{
public:
    /**
     *  Constructor
     * 	@param	name			Function name
     *  @param  function		The native C function
     */
    NativeFunction(const char *name, native_callback_0 function) : Function(name), _type(0) { _function.f0 = function; _ptr.setPointer(this); }
    NativeFunction(const char *name, native_callback_1 function) : Function(name), _type(1) { _function.f1 = function; _ptr.setPointer(this); }
    NativeFunction(const char *name, native_callback_2 function) : Function(name), _type(2) { _function.f2 = function; _ptr.setPointer(this); }
    NativeFunction(const char *name, native_callback_3 function) : Function(name), _type(3) { _function.f3 = function; _ptr.setPointer(this); }
    NativeFunction(const char *name, native_callback_4 function) : Function(name), _type(4) { _function.f4 = function; _ptr.setPointer(this); }
    NativeFunction(const char *name, native_callback_5 function) : Function(name), _type(5) { _function.f5 = function; _ptr.setPointer(this); }
    NativeFunction(const char *name, native_callback_6 function) : Function(name), _type(6) { _function.f6 = function; _ptr.setPointer(this); }
    NativeFunction(const char *name, native_callback_7 function) : Function(name), _type(7) { _function.f7 = function; _ptr.setPointer(this); }

    /**
     *  Destructor
     */
    virtual ~NativeFunction() {}

    /**
     *  Method that gets called every time the function is executed
     *  @param  request     Request environment
     *  @param  params      The parameters that were passed
     *  @return Variable    Return value
     */
    virtual Value invoke(Request &request, Parameters &params) override
    {
        switch (_type) {
        case 0:     _function.f0(); return Value();
        case 1:     _function.f1(params); return Value();
        case 2:     _function.f2(request); return Value();
        case 3:     _function.f3(request, params); return Value();
        case 4:     return _function.f4();
        case 5:     return _function.f5(params);
        case 6:     return _function.f6(request);
        case 7:     return _function.f7(request, params);
        default:    return Value();
        }
    }

private:
    /**
     *  Union of supported callbacks
     *  One of the callbacks will be set 
     */
    union {
        native_callback_0 f0;
        native_callback_1 f1;
        native_callback_2 f2;
        native_callback_3 f3;
        native_callback_4 f4;
        native_callback_5 f5;
        native_callback_6 f6;
        native_callback_7 f7;
    } _function;
    
    /**
     *  The callback that is set
     *  @var integer
     */
    int _type;
};

/**
 *  End of namespace
 */
}

