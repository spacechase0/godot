#ifndef SPACEECS_COMPONENT_H
#define SPACEECS_COMPONENT_H

#include "core/object.h"
#include "core/reference.h"

class Component : public Reference
{
    GDCLASS( Component, Reference );
    OBJ_CATEGORY( "Components" );

protected:
    static void _bind_methods();

public:
    //Ref<Component> duplicate() const;

    virtual String get_component_name() const;

    virtual ~Component();
};

#endif // SPACEECS_COMPONENT_H