#include "component.h"

#include "core/core_string_names.h"
#include "core/list.h"
#include "core/os/os.h"
#include "core/reference.h"
#include "core/resource.h"
#include "core/script_language.h"
#include "core/variant.h"

void Component::_bind_methods()
{
    //ClassDB::bind_method( D_METHOD( "duplicate" ), &Component::duplicate );
    BIND_VMETHOD( MethodInfo( Variant::STRING, "_get_component_name" ) );

    ADD_GROUP( "Component", "component" );
}
/*
Ref<Component> Component::duplicate() const
{
	Ref< Component > comp = ( Component* ) ClassDB::instance( get_class() );
	ERR_FAIL_COND_V( comp.is_null(), Ref< Component >() ) ;

    bool is_valid = false;
	StringName script_property_name = CoreStringNames::get_singleton()->_script;
    Variant script = get(script_property_name, &is_valid);
    if (is_valid)
        comp->set(script_property_name, script);

	List< PropertyInfo > props;
	get_property_list( &props );
    
	for ( List< PropertyInfo >::Element* elem = props.front(); elem; elem = elem->next() )
    {
        String name = elem->get().name;
        if ( !( elem->get().usage & PROPERTY_USAGE_STORAGE ) )
            continue;
        if ( name == script_property_name )
            continue;

        Variant val = get( name ).duplicate( true );
        
        if ( elem->get().usage & PROPERTY_USAGE_DO_NOT_SHARE_ON_DUPLICATE )
        {
            Resource* res = Object::cast_to< Resource >( val );
            if ( res )
                comp->set( name, res->duplicate() );
        }
        else
            comp->set( name, val );
	}

	return comp;
}*/

String Component::get_component_name() const
{
    if ( get_script_instance() )
    {
        //OS::get_singleton()->print("script:%s\n",((String)get_script_instance()->get_script()->get_path()).utf8().get_data());
        Variant ret = get_script_instance()->call( "_get_component_name" );
        if ( ret.get_type() != Variant::STRING )
            OS::get_singleton()->print("Component name was wrong type for: %s %i %s\n", get_script_instance()->get_script()->get_path().utf8().get_data(), ret.get_type(), typeid( * get_script_instance() ).name() );
        return ret;
    }
    //OS::get_singleton()->print("wat\n");
    return get_class_name();
}

Component::~Component()
{
}