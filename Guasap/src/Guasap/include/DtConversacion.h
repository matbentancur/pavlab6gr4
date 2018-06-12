#ifndef DTCONVERSACION_H
#define DTCONVERSACION_H


class DtConversacion {

    private:
        int idConversacion;

    public:
        DtConversacion();
        DtConversacion(int);
        virtual ~DtConversacion();
        int getIdConversacion();
};

#endif // DTCONVERSACION_H
