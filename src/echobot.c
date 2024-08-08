#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "telebot.h"

#include "hfeasy.h"

#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

void USER_FUNC echobot_init(){
    hfthread_create((PHFTHREAD_START_ROUTINE)hf_bot, "hfBot", 512, NULL, HFTHREAD_PRIORITIES_HIGH, NULL, NULL);
}

int hf_bot(void)
{
    printf("Welcome to Echobot\n");

    /*FILE *fp = fopen(".token", "r");
    if (fp == NULL)
    {
        printf("Failed to open .token file\n");
        return -1;
    }

    char token[1024];
    if (fscanf(fp, "%s", token) == 0)
    {
        printf("Failed to read token\n");
        fclose(fp);
        return -1;
    }
    printf("Token: %s\n", token);
    fclose(fp);*/

    char token[1024] = "7484892111:AAFOgVp9L05u3z_tN_D-SRiTa_06aHNddcc";

    telebot_handler_t handle;
    if (telebot_create(&handle, token) != TELEBOT_ERROR_NONE)
    {
        printf("Telebot create failed\n");
        return -1;
    }

    telebot_user_t me;
    if (telebot_get_me(handle, &me) != TELEBOT_ERROR_NONE)
    {
        printf("Failed to get bot information\n");
        telebot_destroy(handle);
        return -1;
    }

    printf("ID: %d\n", me.id);
    printf("First Name: %s\n", me.first_name);
    printf("User Name: %s\n", me.username);

    telebot_put_me(&me);

    int index, count, offset = -1;
    telebot_error_e ret;
    telebot_message_t message;
    telebot_update_type_e update_types[] = {TELEBOT_UPDATE_TYPE_MESSAGE};

    while (1)
    {
        telebot_update_t *updates;
        ret = telebot_get_updates(handle, offset, 20, 0, update_types, 0, &updates, &count);
        if (ret != TELEBOT_ERROR_NONE)
            continue;
        printf("Number of updates: %d\n", count);
        for (index = 0; index < count; index++)
        {
            message = updates[index].message;
            if (message.text)
            {
                printf("%s: %s \n", message.from->first_name, message.text);
                if (strstr(message.text, "/dice"))
                {
                    telebot_send_dice(handle, message.chat->id, false, 0, "");
                }
                else
                {
                    char str[4096];
                    if (strstr(message.text, "/holamundo"))
                    {
                        snprintf(str, SIZE_OF_ARRAY(str), "Morite primer nombre: %s, segundo linga: %s", message.from->first_name, message.from->last_name);
                    }
                    else if(strstr(message.text, "/on")){
                        snprintf(str, SIZE_OF_ARRAY(str), "hola");
                    }
                    else
                    {
                        snprintf(str, SIZE_OF_ARRAY(str), "<i>%s</i>", message.text);
                    }
                    ret = telebot_send_message(handle, message.chat->id, str, "HTML", false, false, updates[index].message.message_id, "");
                }
                if (ret != TELEBOT_ERROR_NONE)
                {
                    printf("Failed to send message: %d \n", ret);
                }
            }
            offset = updates[index].update_id + 1;
        }
        telebot_put_updates(updates, count);

        sleep(1);
    }

    telebot_destroy(handle);

    return 0;
}

