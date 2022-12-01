@GUI::Frame {
    layout: @GUI::VerticalBoxLayout {
        margins: [10]
        spacing: 5
    }
    fixed_width: 350
    fixed_height: 400
    fill_with_background_color: true

    @GUI::GroupBox {
        layout: @GUI::VerticalBoxLayout {
            margins: [8]
        }
        title: "Event Details"

        @GUI::Label {
            text: "Title:"
            text_alignment: "CenterLeft"
        }

        @GUI::TextBox {
            placeholder: "title"
            name: "title"
        }

        @GUI::Label {
            text: "Description:"
            text_alignment: "CenterLeft"
        }

        @GUI::TextEditor {
            placeholder: "description"
            name: "description"
        }

        @GUI::Label {
            text: "Color:"
            text_alignment: "CenterLeft"
        }

        @GUI::ColorInput {
            text: "Event Color"
            name: "color"
        }
    }

    @GUI::GroupBox {
        layout: @GUI::VerticalBoxLayout {
            margins: [16]
        }
        title: "Date and Time"
        fixed_height: 120

        @GUI::Widget {
            layout: @GUI::HorizontalBoxLayout {
                spacing: 4
            }

            @GUI::Label {
                text: "Date:"
                fixed_width: 30
            }

            @GUI::ComboBox {
                model_only: true
                name: "month"
            }

            @GUI::SpinBox {
                name: "day"
                min: 1
                max: 31
            }

            @GUI::SpinBox {
                name: "year"
                min: 1
                max: 9999
            }
        }

        @GUI::Widget {
            layout: @GUI::HorizontalBoxLayout {
                spacing: 4
            }

            @GUI::Label {
                text: "Time:"
                fixed_width: 30
            }

            @GUI::SpinBox {
                name: "hour"
                min: 0
                max: 23
            }

            @GUI::SpinBox {
                name: "minute"
                min: 0
                max: 59
            }
        }
    }

    @GUI::Widget {
        layout: @GUI::HorizontalBoxLayout {
            margin: [8, 0, 0, 0]
            spacing: 6
        }
        fixed_height: 32

        @GUI::DialogButton {
            text: "Delete"
            name: "delete_button"
        }

        @GUI::Widget {}

        @GUI::DialogButton {
            text: "OK"
            name: "ok_button"
        }

        @GUI::DialogButton {
            text: "Cancel"
            name: "cancel_button"
        }
    }
}
