# Usa l'immagine di base di Nginx
FROM nginx:latest

# Copia il file di configurazione personalizzato di Nginx che si trova nella directory in cui è presente il Dockerfile 
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf

# Copia le risorse statiche nella directory di servizio di Nginx
COPY ./firmware/ /usr/share/nginx/html/firmware
