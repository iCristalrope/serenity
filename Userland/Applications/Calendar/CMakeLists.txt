serenity_component(
    Calendar
    TARGETS Calendar
)

compile_gml(CalendarEvent.gml CalendarEventGML.h calendar_event_gml)
compile_gml(CalendarWindow.gml CalendarWindowGML.h calendar_window_gml)

set(SOURCES
    EventDialog.cpp
    main.cpp
)

set(GENERATED_SOURCES
    CalendarEventGML.h
    CalendarWindowGML.h
)

serenity_app(Calendar ICON app-calendar)
target_link_libraries(Calendar PRIVATE LibConfig LibCore LibGfx LibGUI LibMain)
